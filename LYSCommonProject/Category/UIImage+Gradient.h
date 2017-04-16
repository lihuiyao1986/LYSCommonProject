//
//  UIImage+Gradient.h
//  GisHelper
//
//  Created by jk on 2017/4/14.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,GradientDirection){
    TopToBottom = 0,//从上到小
    LeftToRight = 1,//从左到右
    UpLeftToLowRight = 2,//左上到右下
    UpRightToLowLeft = 3,//右上到左下
};

@interface UIImage (Gradient)

#pragma mark - 根据颜色生成渐变图片
+(UIImage*)imageWithColors:(NSArray*)colors gradientDirection:(GradientDirection)drirection size:(CGSize)size;

@end
