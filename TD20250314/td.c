#include <stdio.h>
#include <stdint.h>

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
#if 0
	printf("sizeof(bitmap_file_header)=%lu bytes\n", sizeof(bitmap_file_header));
	printf("sizeof(bitmap_info_header)=%lu bytes\n", sizeof(bitmap_info_header));
	return 0;
#endif

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
#if 0
	const size_t WIDTH_OFFSET = 0x12;
	uint8_t c=0;

#if 0
	for(size_t index=0;index<WIDTH_OFFSET;index++) {
		ret=fread(&c, sizeof(uint8_t), 1, f);
		if (1 != ret)
		{
			printf("Error, unable to read from [%s].\n", filename);
			return 4;
		}
	}
#else
	ret=fseek(f, WIDTH_OFFSET, SEEK_SET);
	if (0 != ret)
	{
		printf("Error, unable to fseek in [%s].\n", filename);
		return 4;
	}
#endif
	uint32_t width=0;
	ret=fread(&width, sizeof(uint32_t), 1, f);
	if (1 != ret)
	{
		printf("Error, unable to read from [%s].\n", filename);
		return 4;
	}
	printf("width = %u pixels\n", width);

	uint32_t height=0;
	ret=fread(&height, sizeof(uint32_t), 1, f);
	if (1 != ret)
	{
		printf("Error, unable to read from [%s].\n", filename);
		return 4;
	}
	printf("height = %u pixels\n", height);

#if 0
	for(size_t index=0;index<2;index++) {
		ret=fread(&c, sizeof(uint8_t), 1, f);
		if (1 != ret)
		{
			printf("Error, unable to read from [%s].\n", filename);
			return 4;
		}
	}
#else
	ret=fseek(f, 2, SEEK_CUR);
	if (0 != ret)
	{
		printf("Error, unable to fseek in [%s].\n", filename);
		return 4;
	}
#endif
	uint16_t bits_per_pixel=0;
	ret=fread(&bits_per_pixel, sizeof(uint16_t), 1, f);
	if (1 != ret)
	{
		printf("Error, unable to read from [%s].\n", filename);
		return 4;
	}
	printf("bits_per_pixel = %u bits\n", bits_per_pixel);


#else
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
#if 0
	printf("pixels : ");
	for(size_t index=0;index<10;index++) {
		uint8_t pixel=0;
		ret=fread(&pixel, sizeof(uint8_t), 1, f);
		if (1 != ret)
		{
			printf("Error, unable to read one pixel from [%s].\n", filename);
			return 4;
		}
		printf("%02X ", pixel);
	}
	puts("");
#else
	for(size_t index=0;index<info_header.width*info_header.height/2;index++) {
		uint8_t pixel=index%info_header.width;
		ret=fwrite(&pixel, sizeof(uint8_t), 1, f);
		if (1 != ret)
		{
			printf("Error, unable to write one pixel to [%s].\n", filename);
			return 4;
		}
	}
#endif
#endif
	// close the file 
	if (0 != fclose(f))
	{
		printf("Error, unable to close [%s].\n", filename);
		return 2;
	};

	return 0;
}


