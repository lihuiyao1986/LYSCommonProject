//
//  NSObject+ScaleFrame.m
//  LYSCommonProject
//
//  Created by jk on 2017/3/8.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import "NSObject+ScaleFrame.h"

@implementation NSObject (ScaleFrame)

-(CGRect)scaleFrame:(CGRect)frame{
    CGFloat autoScaleX = 1.0;
    CGFloat autoScaleY = 1.0;
    if ([UIScreen mainScreen].bounds.size.height > 480){
        autoScaleX = [UIScreen mainScreen].bounds.size.width / 320;
        autoScaleY = [UIScreen mainScreen].bounds.size.height / 568;
    }
    return CGRectMake(frame.origin.x * autoScaleX, frame.origin.y * autoScaleY, frame.size.width * autoScaleX, frame.size.height * autoScaleY);
}

-(CGRect)scaleFrame:(CGFloat)x y:(CGFloat)y width:(CGFloat)width height:(CGFloat)height{
    return [self scaleFrame:CGRectMake(x, y, width, height)];
}

@end
