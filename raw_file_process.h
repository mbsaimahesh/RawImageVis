#ifndef RAW_FILE_PROCESS_H
#define RAW_FILE_PROCESS_H

#include "libraw/libraw.h"
#include "image.hxx"
Image<uint8_t> process_image(const char *file);

#endif // RAW_FILE_PROCESS_H
