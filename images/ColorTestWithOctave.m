I= imread('lena_color.bmp');

imfinfo('lena_color.bmp')

for i=1:3
  for j=1:512
    for k=1:512
      I[i*512+k] = 255-
imshow(I);
