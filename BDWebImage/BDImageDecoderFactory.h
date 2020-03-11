#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BDImage.h"


/**
 获取共享的当前设备的ColorSpace
 */
FOUNDATION_EXPORT CGColorSpaceRef BDCGColorSpaceGetDeviceRGB(void);

/**
 EXIF方向转换到UIImage方向
 */
FOUNDATION_EXPORT UIImageOrientation BDUIImageOrientationFromEXIFOrientation(NSUInteger exifOrientation);

/**
 解码且保证GPU支持的bitmap格式
 */
FOUNDATION_EXPORT CGImageRef BDCGImageCreateDecodedCopy(CGImageRef imageRef, BOOL decodeForDisplay);

FOUNDATION_EXPORT CGImageRef BDCGImageDecompressedAndScaledDownImageCreate(CGImageRef imageRef, BOOL *isDidScaleDown);

FOUNDATION_EXPORT BOOL BDCGImageRefContainsAlpha(CGImageRef imageRef);

FOUNDATION_EXPORT BDImageCodeType BDImageDetectType(CFDataRef data);

FOUNDATION_EXPORT CFStringRef BDUTTypeFromBDImageType(BDImageCodeType type);

@interface BDImageDecoderFactory : NSObject
+ (Class)decoderForImageData:(NSData *)data type:(BDImageCodeType *)type;
@end
