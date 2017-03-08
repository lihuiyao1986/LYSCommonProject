//
//  UIView+LYS.m
//  LYSCommonProject
//
//  Created by jk on 2017/3/8.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import "UIView+LYS.h"

@implementation UIView (LYS)

#pragma mark - 删除所有的子视图
-(void)removeAllSubviews{
    [self.subviews makeObjectsPerformSelector:@selector(removeFromSuperview)];
}

@end
