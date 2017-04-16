//
//  UIColor+image.m
//  LYSCommonProject
//
//  Created by jk on 2017/4/16.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import "UIColor+image.h"

@implementation UIColor (image)


#pragma mark - 创建图片
- (UIImage *)createImageWithColor{
    CGRect rect = CGRectMake(0.0f, 0.0f, 1.0f, 1.0f);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [self CGColor]);
    CGContextFillRect(context, rect);
    UIImage *theImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return theImage;
}

@end
