#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// https://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm

#pragma pack(1)
typedef struct { // 14 bytes
	uint16_t signature;
	uint32_t filesize;
	uint32_t reserved;
	uint32_t data_offset;	
} bitmap_file_header;

typedef struct { // 40 bytes
	uint32_t size;
	uint32_t width;
	uint32_t height;
	uint16_t planes;
	uint16_t bit_per_pixels;
	uint32_t compression;
	uint32_t img_size;
	uint32_t horizontal_resolution;
	uint32_t vertical_resolution;
	uint32_t colors_used;
	uint32_t important_colors;
} bitmap_info_header;
#pragma pack(0)


int main(int argc, const char *argv[])
{
	const char *filename = "./data/im1.bmp";
	char *mode = "rb+"; // rb+ => read and write

	// open the file
	FILE *f = NULL;
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open [%s].\n", filename);
		return 1;
	}

	int ret=0;

	bitmap_file_header file_header;
	bitmap_info_header info_header;

	ret=fread(&file_header, sizeof(bitmap_file_header), 1, f);
	if (1 != ret)
	{
		printf("Error, unable to read bitmap_file_header from [%s].\n", filename);
		return 4;
	}
	ret=fread(&info_header, sizeof(bitmap_info_header), 1, f);
	if (1 != ret)
	{
		printf("Error, unable to read bitmap_info_header from [%s].\n", filename);
		return 4;
	}
	printf("width = %u pixels\n", info_header.width);
	printf("height = %u pixels\n", info_header.height);
	printf("bit_per_pixels = %u bits\n", info_header.bit_per_pixels);
	printf("data_offset = %u bytes\n", file_header.data_offset);

	ret=fseek(f, file_header.data_offset, SEEK_SET);
	if (0 != ret)
	{
		printf("Error, unable to fseek to file_header.data_offset in [%s].\n", filename);
		return 4;
	}


	size_t memory_size = info_header.width*info_header.height*info_header.bit_per_pixels/8;
	printf("memory_size=%lu bytes at line\n", memory_size);
	uint8_t *pixels=NULL;
	pixels=(uint8_t*)malloc(memory_size);
	if(NULL==pixels) {
		printf("Error while allocating memory for pixels at line %d.\n", __LINE__);
	} else {

		ret=fread(pixels, sizeof(uint8_t), info_header.width*info_header.height, f);
		if (info_header.width*info_header.height != ret)
		{
			printf("Error, unable to read pixels\n");
		} else {

			uint8_t val_min=pixels[0];
			uint8_t val_max=pixels[0];
			uint8_t val_mean=0;
			size_t sum_pixels=pixels[0];
			for(size_t index=1;index<info_header.width*info_header.height;index++) {
				val_min=pixels[index]<val_min ? pixels[index] : val_min;
				val_max=pixels[index]>val_max ? pixels[index] : val_max;
				sum_pixels+=pixels[index];
			}
			val_mean=sum_pixels/(info_header.width*info_header.height);
			printf("val_min  : %hhu\n", val_min);
			printf("val_max  : %hhu\n", val_max);
			printf("val_mean : %hhu\n", val_mean);
		}
	
		// end of usage of pixels =>
		free(pixels);
		pixels=NULL;
	}


	// close the file 
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};

	return 0;
}


