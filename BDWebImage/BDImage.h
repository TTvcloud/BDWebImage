#import <UIKit/UIKit.h>
typedef NS_ENUM(NSUInteger, BDImageCodeType) {
    BDImageCodeTypeUnknown = 0, ///< unknown
    BDImageCodeTypeJPEG,        ///< jpeg, jpg
    BDImageCodeTypeJPEG2000,    ///< jp2
    BDImageCodeTypeTIFF,        ///< tiff, tif
    BDImageCodeTypeBMP,         ///< bmp
    BDImageCodeTypeICO,         ///< ico
    BDImageCodeTypeICNS,        ///< icns
    BDImageCodeTypeGIF,         ///< gif
    BDImageCodeTypePNG,         ///< png
    BDImageCodeTypeWebP,        ///< webp
    BDImageCodeTypeHeic,        ///< Heic, imageIO support （ftypheic ....ftypheix ....ftyphevc ....ftyphevx）
    BDImageCodeTypeHeif,        ///< Heif, currently(20180311) no imageIO support （mif1，msf1）
};

static inline NSString *_Nullable imageTypeString(BDImageCodeType type) {
    NSString *text = nil;
    switch (type) {
        case BDImageCodeTypeJPEG:
            text = @"jpeg";
            break;
        case BDImageCodeTypeJPEG2000:
            text = @"jpeg2000";
            break;
        case BDImageCodeTypeTIFF:
            text = @"tiff";
            break;
        case BDImageCodeTypeBMP:
            text = @"bmp";
            break;
        case BDImageCodeTypeICO:
            text = @"ico";
            break;
        case BDImageCodeTypeICNS:
            text = @"icns";
            break;
        case BDImageCodeTypeGIF:
            text = @"gif";
            break;
        case BDImageCodeTypePNG:
            text = @"png";
            break;
        case BDImageCodeTypeWebP:
            text = @"webp";
            break;
        case BDImageCodeTypeHeic:
            text = @"heic";
            break;
        case BDImageCodeTypeHeif:
            text = @"heif";
            break;
        default:
            text = @"unknow";
            break;
    }
    return text;
}

@class BDImageDecoderInternal;

/**
 适用于动图，动图的一帧
 */
@interface BDAnimateImageFrame : NSObject
@property (nonatomic, retain, nullable) UIImage *image;
@property (nonatomic, assign) NSUInteger index;
@property (nonatomic, assign) CFTimeInterval delay;
@property (nonatomic, assign) CFTimeInterval nextFrameTime;
@end

/**
 重写UIImage各个初始化方法，用于支持动图或者需要额外解码时
 */
@interface BDImage : UIImage
@property (nonatomic, readonly)BDImageCodeType codeType;//原始数据编码格式
@property (nonatomic, readonly, nullable)NSString *filePath;//原始文件地址,仅通过URL初始化时存在

/**
 If the image is created from animated image data (multi-frame GIF/APNG/WebP),
 this property stores the original image data.
 */
@property (nullable, nonatomic, readonly) NSData *animatedImageData;

@property (nonatomic, readonly)BOOL isAnimateImage;//动图[gif|webp|apng],且帧数大于一
@property (nonatomic, readonly)NSUInteger frameCount;//帧数
@property (nonatomic, readonly)NSUInteger loopCount;//循环次数
NS_ASSUME_NONNULL_BEGIN
+ (nullable BDImage *)imageWithContentsOfFile:(NSString *)path;

+ (nullable BDImage *)imageNamed:(NSString *)name;

+ (nullable BDImage *)imageWithData:(NSData *)data;

+ (nullable BDImage *)imageWithData:(NSData *)data scale:(CGFloat)scale;

+ (nullable BDImage *)imageWithData:(NSData *)data scale:(CGFloat)scale decodeForDisplay:(BOOL)decode error:(NSError *__autoreleasing *)error;

+ (nullable BDImage *)imageWithData:(NSData *)data scale:(CGFloat)scale decodeForDisplay:(BOOL)decode shouldScaleDown:(BOOL)shouldScaleDown error:(NSError *__autoreleasing *)error;

- (nullable BDAnimateImageFrame *)frameAtIndex:(NSInteger)index;

- (instancetype)initWithCoderInternal:(BDImageDecoderInternal *)decoder;
NS_ASSUME_NONNULL_END
@end
