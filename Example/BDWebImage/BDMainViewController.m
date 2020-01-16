//
//  BDMainViewController.m
//  BDWebImage_Example
//
//  Created by Lin Yong on 2019/4/23.
//  Copyright © 2019年 Bytedance.com. All rights reserved.
//

#import "BDMainViewController.h"
#import "BDViewController.h"
#import <BDWebImageToB/BDWebImage.h>
#import "RCCollectionViewSceneViewController.h"


@implementation BDMainViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.items.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:@"cell"];
    }
    cell.textLabel.text = self.items[indexPath.row][@"name"];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
    
    void(^action)(void) = self.items[indexPath.row][@"action"];
    action();
}

- (NSArray *)items {
    if (!_items) {
        _items = @[
                   @{
                       @"name": @"Clear Cache",
                       @"action": ^{
                           [[BDWebImageManager sharedManager].imageCache clearDiskWithBlock:^{
                               [[BDWebImageManager sharedManager].imageCache clearMemory];
                               [[BDWebImageManager sharedManager].imageCache clearDiskWithBlock:nil];
                           }];
                       }
                       },
                   @{
                       @"name": @"WebP",
                       @"action": ^{
                           BDViewController *vc = [[BDViewController alloc] init];
                           vc.showType = BDImageShowTypeWebP;
                           [self.navigationController pushViewController:vc animated:YES];
                       }
                    },
                   @{
                       @"name": @"GIF",
                       @"action": ^{
                           BDViewController *vc = [[BDViewController alloc] init];
                           vc.showType = BDImageShowTypeGIF;
                           [self.navigationController pushViewController:vc animated:YES];
                       }
                    },
                   @{
                       @"name": @"CollectionView",
                       @"action": ^{
                           [self pushCollectionVC];
                       }
                    },
                   @{
                       @"name": @"更多用例请参考Tests",
                       @"action": ^{
                       }
                    },
                   ];
    }
    return _items;
}

- (void)pushCollectionVC {
    [self.navigationController pushViewController:[[RCCollectionViewSceneViewController alloc] init] animated:NO];
}

@end
