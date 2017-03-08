//
//  TypeTransformTool.h
//  LYSCommonProject
//
//  Created by jk on 2017/3/8.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TypeTransformTool : NSObject

#pragma mark - String->int
+(int)strToInt:(NSString*)target;

#pragma mark - int->String
+(NSString*)intToStr:(int)target;

#pragma mark - String->float
+(float)strToFloat:(NSString*)target;

#pragma mark - float->String
+(NSString*)floatToStr:(float)target;

#pragma mark - nsdata->String
+(NSString*)nsdataToStr:(NSData*)target;

#pragma mark - String->nsdata
+(NSData*)strToNSData:(NSString*)target;

#pragma mark - base64 String->nsdata
+(NSData*)strBase64ToNSData:(NSString*)target;

#pragma mark - nsdata-> base64 String
+(NSString*)nsdataToBase64Str:(NSData*)target;

#pragma mark - nsdata-> image
+(UIImage*)nsdataToImage:(NSData*)target;

#pragma mark - image -> nsdata
+(NSData*)imageToNSData:(UIImage*)target;

@end
