#import <Foundation/Foundation.h>
extern NSString *const BDWebImageErrorDomain;

typedef NS_ENUM(NSInteger, BDWebImageError)
{
    BDWebImageCancelled     = NSURLErrorCancelled,  //用户主动取消 -999
    BDWebImageBadImageURL   = NSURLErrorBadURL,     //URL错误导致初始化请求失败 -1000
    BDWebImageBadImageData  = 900001,               //返回数据不能解析
    BDWebImageEmptyImage    = 900002,               //解析完成图片为空像素
    BDWebImageInternalError = 900003,               //内部逻辑错误
};


