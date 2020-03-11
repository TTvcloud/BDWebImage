#ifndef BDWebImageMacro_h
#define BDWebImageMacro_h

#ifndef dispatch_queue_async_safe
#define dispatch_queue_async_safe(queue, block)\
if (strcmp(dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL), dispatch_queue_get_label(queue)) == 0) {\
    block();\
} else {\
    dispatch_async(queue, block);\
}
#endif

#ifndef dispatch_main_async_safe
#define dispatch_main_async_safe(block) dispatch_queue_async_safe(dispatch_get_main_queue(), block)
#endif

#ifndef isEmptyString
#define isEmptyString(str) (!str || ![str isKindOfClass:[NSString class]] || str.length == 0)
#endif

#ifndef isEmptyArray
#define isEmptyArray(array) (!array || ![array isKindOfClass:[NSArray class]] || array.count == 0)
#endif

#ifndef isEmptyDictionary
#define isEmptyDictionary(dict) (!dict || ![dict isKindOfClass:[NSDictionary class]] || ((NSDictionary *)dict).count == 0)
#endif

#ifndef BD_CATEGORY_PROPERTY
#define BD_CATEGORY_PROPERTY
#import <objc/runtime.h>
#define BD_GET_PROPERTY(property) objc_getAssociatedObject(self, @selector(property));
#define BD_SET_STRONG(property) objc_setAssociatedObject(self, @selector(property), property, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
#define BD_SET_COPY(property) objc_setAssociatedObject(self, @selector(property), property, OBJC_ASSOCIATION_COPY_NONATOMIC);
#define BD_SET_UNSAFE_UNRETAINED(property) objc_setAssociatedObject(self, @selector(property), property, OBJC_ASSOCIATION_ASSIGN);
#define BD_SET_ASSIGN(property, value) objc_setAssociatedObject(self, @selector(property), value, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
#define BD_SET_WEAK(property) id __weak __weak_object = property; \
id (^__weak_block)(void) = ^{ return __weak_object; }; \
objc_setAssociatedObject(self, @selector(property), __weak_block, OBJC_ASSOCIATION_COPY);
#define BD_GET_WEAK(property) objc_getAssociatedObject(self, @selector(property)) ? ((id (^)(void))objc_getAssociatedObject(self, @selector(property)))() : nil;
#endif

#endif /* BDWebImageMacro_h */
