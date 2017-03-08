//
//  NSObject+ScaleFrame.h
//  LYSCommonProject
//
//  Created by jk on 2017/3/8.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSObject (ScaleFrame)

#pragma mark - 按比例放大
- (CGRect)scaleFrame:(CGRect)frame;

#pragma mark - 按比例放大
- (CGRect)scaleFrame:(CGFloat)x y:(CGFloat)y width:(CGFloat)width height:(CGFloat)height;

@end
