#include "raw_file_process.h"


Image<uint8_t> process_image(const char *file)
{
  LibRaw iProcessor;

  iProcessor.open_file(file);
  iProcessor.unpack();
  iProcessor.dcraw_process();
  const int imwidth{iProcessor.imgdata.sizes.width};
  const int imheight{iProcessor.imgdata.sizes.height};
  const int nchannels{3};
  Image<uint8_t> processed_image(imwidth,imheight,3);
  iProcessor.copy_mem_image(processed_image.imdata, processed_image.imwidth*processed_image.nchannels, 1);
  iProcessor.recycle();
  return processed_image;
}
