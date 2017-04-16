//
//  VMaskTextField+BottomBorder.m
//  GisHelper
//
//  Created by jk on 2017/4/14.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import "UITextField+BottomBorder.h"
#import <objc/runtime.h>

static void *bottomBorderColorKey = @"bottomBorderColorKey";
static void *bottomBorderWidthKey = @"bottomBorderWidthKey";

@implementation UITextField (BottomBorder)

-(void)setBottomBorderColor:(UIColor *)bottomBorderColor{
    objc_setAssociatedObject(self, &bottomBorderColorKey, bottomBorderColor, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    [self setNeedsDisplay];
}

-(UIColor *)bottomBorderColor{
    return objc_getAssociatedObject(self, &bottomBorderColorKey);
}

-(void)setBorderWidth:(CGFloat )borderWidth{
    objc_setAssociatedObject(self, &bottomBorderWidthKey, [NSString stringWithFormat:@"%f",borderWidth], OBJC_ASSOCIATION_ASSIGN);
    [self setNeedsDisplay];
}

-(CGFloat)borderWidth{
    return [objc_getAssociatedObject(self, &bottomBorderWidthKey) floatValue];

}
- (void)drawRect:(CGRect)rect {
    [super drawRect:rect];
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, self.bottomBorderColor.CGColor);
    CGContextFillRect(context, CGRectMake(0, CGRectGetHeight(self.frame) - self.borderWidth, CGRectGetWidth(self.frame), self.borderWidth));
}

@end
