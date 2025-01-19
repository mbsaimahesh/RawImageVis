#ifndef IMAGE_HXX
#define IMAGE_HXX

template <typename T>
class Image {
 public:
  Image(const int w, const int h, const int c)
      : imwidth{w}, imheight{h}, nchannels{c}, imdata{new T[w * h * c]} {}

  Image(Image&& obj) 
      : imwidth{obj.imwidth},
        imheight{obj.imheight},
        nchannels{obj.nchannels},
        imdata{obj.imdata}
  {
    obj.imdata = nullptr;
  }
  
  ~Image() {
    delete[] imdata;
  }
  T* imdata;
  const int imwidth;
  const int imheight;
  const int nchannels;
};

#endif