//
//  BDImageDecoderImageIO.h
//  BDWebImage
//
//  Created by lizhuoli on 2017/12/13.
//

#import "BDImageDecoderInternal.h"
#import <ImageIO/ImageIO.h>

@interface BDImageDecoderImageIO : BDImageDecoderInternal

- (instancetype)initWithImageSource:(CGImageSourceRef)imageSource;

- (void)updateImage:(NSData *)data;

@end
