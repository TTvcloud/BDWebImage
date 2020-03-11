#import <Foundation/Foundation.h>

@interface BDWebImageUtil : NSObject

+ (UIImage *)decodeImageData:(NSData *)data imageClass:(__unsafe_unretained Class)imageClass scale:(CGFloat)scale decodeForDisplay:(BOOL)decode shouldScaleDown:(BOOL)scaleDown;
@end
