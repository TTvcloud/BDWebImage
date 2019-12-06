//
//  BDViewController.h
//  BDWebImage
//
//  Created by ghlsb@hotmail.com on 11/28/2017.
//  Copyright (c) 2017 ghlsb@hotmail.com. All rights reserved.
//

@import UIKit;

typedef enum : NSUInteger {
    BDImageShowTypeWebP,
    BDImageShowTypeGIF,
} BDImageShowType;

@interface BDViewController : UIViewController
@property (nonatomic, assign) BDImageShowType showType;
@end
