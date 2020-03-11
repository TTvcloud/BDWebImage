#import <UIKit/UIKit.h>
#import "BDWebImageManager.h"

@class BDBaseTransformer;

@interface UIButton (BDWebImage)
- (nullable BDWebImageRequest *)bd_setImageWithURL:(nonnull NSURL *)url forState:(UIControlState)state;
- (nullable BDWebImageRequest *)bd_setImageWithURL:(nonnull NSURL *)url
                                          forState:(UIControlState)state
                                  placeholderImage:(nullable UIImage *)placeholder;

- (nullable BDWebImageRequest *)bd_setImageWithURL:(nonnull NSURL *)url
                                          forState:(UIControlState)state
                                  placeholderImage:(nullable UIImage *)placeholder
                                        decryption:(nullable BDImageRequestDecryptBlock)decrption;

- (nullable BDWebImageRequest *)bd_setImageWithURL:(nonnull NSURL *)url
                                          forState:(UIControlState)state
                                  placeholderImage:(nullable UIImage *)placeholder
                                          progress:(nullable BDImageRequestProgressBlock)progressBlock
                                         completed:(nullable BDImageRequestCompletedBlock)completedBlock;

- (nullable BDWebImageRequest *)bd_setImageWithURL:(nonnull NSURL *)url
                                          forState:(UIControlState)state
                                  placeholderImage:(nullable UIImage *)placeholder
                                           options:(BDImageRequestOptions)options
                                          progress:(nullable BDImageRequestProgressBlock)progressBlock
                                         completed:(nullable BDImageRequestCompletedBlock)completedBlock;

- (nullable BDWebImageRequest *)bd_setImageWithURL:(nonnull NSURL *)url
                                          forState:(UIControlState)state
                                  placeholderImage:(nullable UIImage *)placeholder
                                         completed:(nullable BDImageRequestCompletedBlock)completedBlock;

- (nullable BDWebImageRequest *)bd_setImageWithURL:(nonnull NSURL *)url
                                          forState:(UIControlState)state
                                  placeholderImage:(nullable UIImage *)placeholder
                                           options:(BDImageRequestOptions)options
                                         cacheName:(nullable NSString *)cacheName
                                          progress:(nullable BDImageRequestProgressBlock)progressBlock
                                         completed:(nullable BDImageRequestCompletedBlock)completedBlock;

- (nullable BDWebImageRequest *)bd_setImageWithURLs:(nonnull NSArray *)URLs
                                           forState:(UIControlState)state
                                   placeholderImage:(nullable UIImage *)placeholder
                                            options:(BDImageRequestOptions)options
                                        transformer:(nullable BDBaseTransformer *)transformer
                                           progress:(nullable BDImageRequestProgressBlock)progressBlock
                                          completed:(nullable BDImageRequestCompletedBlock)completedBlock;

- (nullable BDWebImageRequest *)bd_setImageWithURL:(nonnull NSURL *)url
                                   alternativeURLs:(nullable NSArray<NSURL *> *)alternativeURLs
                                          forState:(UIControlState)state
                                  placeholderImage:(nullable UIImage *)placeholder
                                           options:(BDImageRequestOptions)options
                                         cacheName:(nullable NSString *)cacheName
                                       transformer:(nullable BDBaseTransformer *)transformer
                                          progress:(nullable BDImageRequestProgressBlock)progressBlock
                                         completed:(nullable BDImageRequestCompletedBlock)completedBlock;

- (nullable BDWebImageRequest *)bd_setImageWithURL:(nonnull NSURL *)url
                                   alternativeURLs:(nullable NSArray<NSURL *> *)alternativeURLs
                                          forState:(UIControlState)state
                                  placeholderImage:(nullable UIImage *)placeholder
                                           options:(BDImageRequestOptions)options
                                   timeoutInterval:(CFTimeInterval)timeoutInterval
                                         cacheName:(nullable NSString *)cacheName
                                       transformer:(nullable BDBaseTransformer *)transformer
                                          progress:(nullable BDImageRequestProgressBlock)progressBlock
                                         completed:(nullable BDImageRequestCompletedBlock)completedBlock;

- (nullable BDWebImageRequest *)bd_setImageWithURL:(nonnull NSURL *)url
                                   alternativeURLs:(nullable NSArray<NSURL *> *)alternativeURLs
                                          forState:(UIControlState)state
                                  placeholderImage:(nullable UIImage *)placeholder
                                           options:(BDImageRequestOptions)options
                                   timeoutInterval:(CFTimeInterval)timeoutInterval
                                         cacheName:(nullable NSString *)cacheName
                                       transformer:(nullable BDBaseTransformer *)transformer
                                          progress:(nullable BDImageRequestProgressBlock)progressBlock
                                         completed:(nullable BDImageRequestCompletedBlock)completedBlock
                                        decryption:(nullable BDImageRequestDecryptBlock)decrption;

#pragma mark - Backgroud Method

- (nullable BDWebImageRequest *)bd_setBackgroundImageWithURL:(nonnull NSURL *)url
                                                    forState:(UIControlState)state;

- (nullable BDWebImageRequest *)bd_setBackgroundImageWithURL:(nonnull NSURL *)url
                                                    forState:(UIControlState)state
                                            placeholderImage:(nullable UIImage *)placeholder;

- (nullable BDWebImageRequest *)bd_setBackgroundImageWithURL:(nonnull NSURL *)url
                                                    forState:(UIControlState)state
                                            placeholderImage:(nullable UIImage *)placeholder
                                                   completed:(nullable BDImageRequestCompletedBlock)completedBlock;;

- (nullable BDWebImageRequest *)bd_setBackgroundImageWithURL:(nonnull NSURL *)url
                                                    forState:(UIControlState)state
                                            placeholderImage:(nullable UIImage *)placeholder
                                                     options:(BDImageRequestOptions)options
                                                    progress:(nullable BDImageRequestProgressBlock)progressBlock
                                                   completed:(nullable BDImageRequestCompletedBlock)completedBlock;;

- (nullable BDWebImageRequest *)bd_setBackgroundImageWithURL:(nonnull NSURL *)url
                                                    forState:(UIControlState)state
                                            placeholderImage:(nullable UIImage *)placeholder
                                                     options:(BDImageRequestOptions)options
                                                   cacheName:(nullable NSString *)cacheName
                                                    progress:(nullable BDImageRequestProgressBlock)progressBlock
                                                   completed:(nullable BDImageRequestCompletedBlock)completedBlock;;

- (nullable BDWebImageRequest *)bd_setBackgroundImageWithURLs:(nonnull NSArray *)URLs
                                                     forState:(UIControlState)state
                                             placeholderImage:(nullable UIImage *)placeholder
                                                      options:(BDImageRequestOptions)options
                                                  transformer:(nullable BDBaseTransformer *)transformer
                                                     progress:(nullable BDImageRequestProgressBlock)progressBlock
                                                    completed:(nullable BDImageRequestCompletedBlock)completedBlock;;

//- (nullable BDWebImageRequest *)bd_setBackgroundImageWithURLs:(nonnull NSArray *)URLs
//                                                     forState:(UIControlState)state
//                                             placeholderImage:(nullable UIImage *)placeholder
//                                                      options:(BDImageRequestOptions)options
//                                              timeoutInterval:(CFTimeInterval)timeoutInterval
//                                                  transformer:(nullable BDBaseTransformer *)transformer
//                                                     progress:(nullable BDImageRequestProgressBlock)progressBlock
//                                                    completed:(nullable BDImageRequestCompletedBlock)completedBlock;;
- (void)bd_cancelImageLoadForState:(UIControlState)state;
- (void)bd_cancelBackgroundImageLoadForState:(UIControlState)state;
- (nullable NSURL *)bd_imageURLForState:(UIControlState)state;
@end

