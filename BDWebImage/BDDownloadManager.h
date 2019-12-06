//
//  BDDownloadManager.h
//  BDWebImage
//
//  Created by 刘诗彬 on 2017/11/28.
//

#import <Foundation/Foundation.h>
#import "BDDownloadTask.h"
#import "BDWebImageDownloader.h"

/**
 如果任务超过并行上限则会进入等待队列，BDDownloadStackMode指定了等待队列的模式
 */

typedef NS_ENUM(NSUInteger, BDDownloadStackMode)
{
    BDDownloadStackModeFIFO = 0,//先进先出
    BDDownloadStackModeLIFO = 1,//后进先出
    BDDownloadStackModeDefault = BDDownloadStackModeFIFO,
};

@class BDDownloadManager;
@protocol BDDownloadManagerTaskDelegate
- (void)downloader:(BDDownloadManager *)downloader task:(BDDownloadTask *)task failedWithError:(NSError *)error;
- (void)downloader:(BDDownloadManager *)downloader task:(BDDownloadTask *)task finishedWithData:(NSData *)data savePath:(NSString *)savePath;

@optional
- (void)downloader:(BDDownloadManager *)downloader task:(BDDownloadTask *)task receivedSize:(NSInteger)receivedSize expectedSize:(NSInteger)expectedSize;
- (void)downloader:(BDDownloadManager *)downloader task:(BDDownloadTask *)task didReceiveData:(NSData *)data;
@end

@interface BDDownloadManager : NSObject
@property (nonatomic, weak) id<BDDownloadManagerTaskDelegate> delegate;
@property (nonatomic, assign) BDDownloadStackMode stackMode;//等待队列模式
@property (nonatomic, assign) NSUInteger maxConcurrentTaskCount;//最大同时下载任务
@property (nonatomic, strong) NSString *tempPath;//临时文件缓存位置，默认为NSTemporaryDirectory();
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *defaultHeaders;//http request default headers
@property (nonatomic, assign) BOOL downloadResumeEnabled;//是否支持断点续传

@property (nonatomic, strong) NSOperationQueue *operationQueue;//具体执行下载任务的queue
@property (nonatomic, strong, readonly) NSArray<BDDownloadTask *> *allTasks;//当前所有下载任务
@property (nonatomic, assign) Class downloadTaskClass;//具体执行下载任务实例的类
@property (nonatomic, assign) CFTimeInterval timeoutInterval;
@property (nonatomic, assign) CFTimeInterval timeoutIntervalForResource;
@property (nonatomic, assign) BOOL enableLog;
/**
 请求url并返回对应task，如果已有相同identifier的现在任务存在则返回已有task
 
 @param immediately 是否忽略队列立即开始请求，否则走队列逻辑
 @return 返回对应task
 */
- (BDDownloadTask *)downloadWithURL:(NSURL *)url identifier:(NSString *)identifier startImmediately:(BOOL)immediately;

/**
 返回identifier对应的task
 */
- (BDDownloadTask *)taskWithIdentifier:(NSString *)identifier;
@end
