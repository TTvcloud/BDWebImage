//
//  BDWebImageManager.h
//  BDWebImage
//
//  Created by 刘诗彬 on 2017/11/28.
//

#import <Foundation/Foundation.h>
#import "BDWebImageRequest.h"
#import "BDImageCache.h"
#import "BDWebImageURLFilter.h"
#import "BDWebImageDownloader.h"

#define ENABLE_LOG ([BDWebImageManager sharedManager].enableLog)

@class BDWebImageDecoder;
@class BDDownloadManager;
@class BDBaseTransformer;

NS_ASSUME_NONNULL_BEGIN
@interface BDWebImageManager : NSObject
@property (nonatomic, strong) NSString *sdkVersion;
@property (nonatomic, strong) NSString *deviceId;
@property (nonatomic, strong) NSString *appId;

@property (nonatomic, retain, readonly)BDImageCache *imageCache;//默认缓存
@property (nonatomic, retain)BDWebImageDecoder *decoder;
@property (nonatomic, retain)BDWebImageURLFilter *urlFilter;//决定URL如何计算为requestkey,例如多个CND域名或者文件后缀可以映射为相同请求
@property (nonatomic, retain, nullable)id<BDWebImageDownloader> downloadManager;//下载任务manager
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *downloadManagerDefaultHeaders;//http request default headers
@property (nonatomic, assign)BDDownloadImpl downloadImpl;//下载实现，默认用chromium
@property (nonatomic, assign)CFTimeInterval timeoutInterval;//服务器响应的默认超时时间
/**
 资源下载的默认超时时间，只针对 BDImageProgressiveDownload 生效
 */
@property (nonatomic, assign)CFTimeInterval timeoutIntervalForResource;
@property (nonatomic, assign)BOOL insulatedCache;//如果设置为YES各缓存实例之间互不干扰
@property (nonatomic, assign) BOOL isDecoderForDisplay; /// 全局控制预解码，默认为YES，或者可以针对单独的请求使用 BDImageNotDecoderForDisplay 控制。https://docs.bytedance.net/doc/kZWZOhofAtlbTHoG8IGZJd
@property (nonatomic, assign) BOOL enableLog; // Log DEBUG and INFO level, default: YES
@property (nonatomic, assign) BOOL enableMultiThreadHeicDecoder; // default: NO

+ (instancetype )sharedManager;

/**
 根据指定的业务类型初始化一个Manager实例，存储，优先级调度等配置，与默认实例隔离
 
 @param category 业务类型，传空的话仍然返回新实例，但是存储与默认实例相同
 @return Manager实例
 */
- (instancetype )initWithCategory:(nullable NSString *)category NS_DESIGNATED_INITIALIZER;

/**
 注册不同的缓存实例，可以有独立不同的缓存策略，具体请求根据"cacheName"决定如何使用缓存，如果多个同时命中则以priority决定，同一张图保证只存在一个cache实例里
 */
- (void)registCache:(BDImageCache *)cache forKey:(NSString *)key;
- (BDImageCache *)cacheForKey:(NSString *)key;

- (void)requestImage:(BDWebImageRequest *)request;

/**
 根据request的category返回指定请求
 */
- (NSArray<BDWebImageRequest *> *)requestsWithCategory:(NSString *)category;

/**
 预加载指定图片
 */
- (NSArray<BDWebImageRequest *> *)prefetchImagesWithURLs:(NSArray<NSURL *> *)urls category:(nullable NSString *)category options:(BDImageRequestOptions)options;
- (BDWebImageRequest *)prefetchImageWithURL:(NSURL *)url category:(NSString *)category options:(BDImageRequestOptions)options;

/**
 返回所有预加载请求
 */
- (NSArray<BDWebImageRequest *> *)allPrefetchs;

/**
 取消所有预加载请求
 */
- (void)cancelAllPrefetchs;

/**
 取消所有请求
 */
- (void)cancelAll;

/**
 获取一个URL对应的requestkey,例如多个CND域名或者文件后缀可以映射为相同请求
 
 @param url 图片地址
 @return requestkey
 */
- (NSString *)requestKeyWithURL:(nullable NSURL *)url;

/**
 立即发起请求，并返回请求实例，具体参数说明参见BDWebImageRequest.h
 Note:如果命中内存图片默认不会提供data，需要提供data请加上BDImageRequestNeedCachePath
 */
- (BDWebImageRequest *)requestImage:(NSURL *)url
                            options:(BDImageRequestOptions)options
                           complete:(nullable BDImageRequestCompletedBlock)complete;

- (BDWebImageRequest *)requestImage:(NSURL *)url
                           progress:(nullable BDImageRequestProgressBlock)progress
                           complete:(nullable BDImageRequestCompletedBlock)complete;

- (BDWebImageRequest *)requestImage:(NSURL *)url
                    alternativeURLs:(nullable NSArray<NSURL *> *)alternativeURLs
                            options:(BDImageRequestOptions)options
                          cacheName:(nullable NSString *)cacheName
                           progress:(nullable BDImageRequestProgressBlock)progress
                           complete:(nullable BDImageRequestCompletedBlock)complete;

- (BDWebImageRequest *)requestImage:(NSURL *)url
                    alternativeURLs:(nullable NSArray<NSURL *> *)alternativeURLs
                            options:(BDImageRequestOptions)options
                          cacheName:(nullable NSString *)cacheName
                        transformer:(nullable BDBaseTransformer *)transformer
                           progress:(nullable BDImageRequestProgressBlock)progress
                           complete:(nullable BDImageRequestCompletedBlock)complete;

- (nullable BDWebImageRequest *)requestImage:(nullable NSURL *)url
                    alternativeURLs:(nullable NSArray<NSURL *> *)alternativeURLs
                            options:(BDImageRequestOptions)options
                    timeoutInterval:(CFTimeInterval)timeoutInterval
                          cacheName:(nullable NSString *)cacheName
                        transformer:(nullable BDBaseTransformer *)transformer
                           progress:(nullable BDImageRequestProgressBlock)progress
                           complete:(nullable BDImageRequestCompletedBlock)complete;

- (nullable BDWebImageRequest *)requestImage:(NSURL *)url
                    alternativeURLs:(nullable NSArray<NSURL *> *)alternativeURLs
                            options:(BDImageRequestOptions)options
                    timeoutInterval:(CFTimeInterval)timeoutInterval
                          cacheName:(nullable NSString *)cacheName
                        transformer:(nullable BDBaseTransformer *)transformer
                       decryptBlock:(nullable BDImageRequestDecryptBlock)decryptBlock
                           progress:(nullable BDImageRequestProgressBlock)progress
                           complete:(nullable BDImageRequestCompletedBlock)complete;

NS_ASSUME_NONNULL_END

@end
