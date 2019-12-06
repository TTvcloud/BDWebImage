//
//  BDWebImageUtil.h
//  BDWebImage
//
//  Created by Lin Yong on 2019/2/11.
//

#import <Foundation/Foundation.h>

@interface BDWebImageUtil : NSObject

+ (UIImage *)decodeImageData:(NSData *)data imageClass:(__unsafe_unretained Class)imageClass scale:(CGFloat)scale decodeForDisplay:(BOOL)decode shouldScaleDown:(BOOL)scaleDown;
@end
