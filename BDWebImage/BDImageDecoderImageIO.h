#import "BDImageDecoderInternal.h"
#import <ImageIO/ImageIO.h>

@interface BDImageDecoderImageIO : BDImageDecoderInternal

- (instancetype)initWithImageSource:(CGImageSourceRef)imageSource;

- (void)updateImage:(NSData *)data;

@end
