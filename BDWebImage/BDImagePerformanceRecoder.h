#import <Foundation/Foundation.h>
#import "BDImageCache.h"
#import "BDWebImageRequest.h"
#import "BDImage.h"


@interface BDImagePerformanceRecoder : NSObject

@property (nonatomic, copy, readwrite) NSString *identifier;/** 请求标示 */
@property (nonatomic, copy, readwrite) NSString *category;/** 所属模块 */

@property (nonatomic, strong, readwrite) NSURL *imageURL; /** 图片url*/
@property (nonatomic, strong, readwrite) NSString *mimeType;/** 图片类型*/

@property (nonatomic, assign, readwrite) double timeStamp;/** 开始时间戳 */
@property (nonatomic, assign, readwrite) double overallStartTime;/** 整体开始时间 */
@property (nonatomic, assign, readwrite) BDImageRequestOptions options; /** 请求设置 */

@property (nonatomic, strong, readwrite) NSError *error;
@property (nonatomic, assign, readwrite) NSInteger statusCode;/** http请求状态码*/

//Resolition
@property (nonatomic, assign, readwrite) CGSize requestImageSize; /** 业务请求的size */
@property (nonatomic, assign, readwrite) CGSize originalImageSize;/** 图片原始的size */

//Cache
@property (nonatomic, assign, readwrite) double cacheSeekStartTime;/** 缓存开始查找时间 */
@property (nonatomic, assign, readwrite) double cacheSeekEndTime;/** 缓存结束查找时间 */
@property (nonatomic, readonly) double cacheSeekDuration;/** 缓存查找耗时 单位ms */
@property (nonatomic, assign, readwrite) BDImageCacheType cacheType;/** 命中缓存类型 */
    
// queue
@property (nonatomic, readonly) double queueDuration;/** 排队耗时 单位ms */

//Download
@property (nonatomic, assign, readwrite) double downloadStartTime;/** 下载开始时间 */
@property (nonatomic, assign, readwrite) double downloadEndTime;/** 下载结束时间 */
@property (nonatomic, strong, readwrite) NSNumber *DNSDuration;/** DNS耗时 单位ms */
@property (nonatomic, strong, readwrite) NSNumber *connetDuration;/** 建立连接耗时 单位ms */
@property (nonatomic, strong, readwrite) NSNumber *sslDuration;/** SSL建连耗时 单位ms */
@property (nonatomic, strong, readwrite) NSNumber *sendDuration;/** 发送耗时 单位ms */
@property (nonatomic, strong, readwrite) NSNumber *waitDuration;/** 等待耗时 单位ms */
@property (nonatomic, strong, readwrite) NSNumber *receiveDuration;/** 接收耗时 单位ms */
@property (nonatomic, readonly) double downloadDuration;/** 下载总体耗时 单位ms */

@property (nonatomic, assign, readwrite) double totalBytes;   /** 图片大小 单位byte */
@property (nonatomic, assign, readwrite) double receivedBytes; /** 已经接收的图片大小 单位byte */
@property (nonatomic, strong, readwrite) NSNumber *isSocketReused;
@property (nonatomic, strong, readwrite) NSNumber *isCached;
@property (nonatomic, strong, readwrite) NSNumber *isFromProxy;
@property (nonatomic, copy,   readwrite) NSString *remoteIP;
@property (nonatomic, strong, readwrite) NSNumber *remotePort;
@property (nonatomic, copy,   readwrite) NSString *requestLog;
@property (nonatomic, strong, readwrite) NSString *nwSessionTrace;/*图片系统在response header中增加的追踪信息，目前包含回复时间戳和处理总延迟*/



//Decode
@property (nonatomic, assign, readwrite) BDImageCodeType codeType;/** 图片编码方式 */
@property (nonatomic, assign, readwrite) double decodeStartTime;/** 解码开始时间 */
@property (nonatomic, assign, readwrite) double decodeEndTime;/** 解码结束时间 */
@property (nonatomic, readonly) double decodeDuration;/** 解码耗时 单位ms */

//setImage
@property (nonatomic, assign, readwrite) double cacheImageBeginTime;/** 缓存图片开始时间 */
@property (nonatomic, assign, readwrite) double cacheImageEndTime;/** 缓存图片结束时间 */
@property (nonatomic, readonly) double cacheImageDuration;/** 缓存图片耗时 单位ms */

@property (nonatomic, assign, readwrite) double overallEndTime;/** 整体结束时间 */
@property (nonatomic, readonly) double overallDuration;/** 整体耗时 单位ms */

@end
