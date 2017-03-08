//
//  TypeTransformTool.m
//  LYSCommonProject
//
//  Created by jk on 2017/3/8.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import "TypeTransformTool.h"

@implementation TypeTransformTool

#pragma mark - String->int
+(int)strToInt:(NSString*)target{
    return [target intValue];
}

#pragma mark - int->String
+(NSString*)intToStr:(int)target{
    return [NSString stringWithFormat:@"%d",target];
}

#pragma mark - String->float
+(float)strToFloat:(NSString*)target{
    return [target floatValue];
}

#pragma mark - float->String
+(NSString*)floatToStr:(float)target{
    return [NSString stringWithFormat:@"%f",target];

}

#pragma mark - nsdata->String
+(NSString*)nsdataToStr:(NSData*)target{
    return [[NSString alloc] initWithData:target encoding:NSUTF8StringEncoding];
}

#pragma mark - String->nsdata
+(NSData*)strToNSData:(NSString*)target{
    return [target dataUsingEncoding:NSUTF8StringEncoding];
}

#pragma mark - base64 String->nsdata
+(NSData*)strBase64ToNSData:(NSString*)target{
    return [[NSData alloc]initWithBase64EncodedString:target options:0];
}

#pragma mark - nsdata-> base64 String
+(NSString*)nsdataToBase64Str:(NSData*)target{
    return [target base64EncodedStringWithOptions:0];
}

#pragma mark - nsdata-> image
+(UIImage*)nsdataToImage:(NSData*)target{
    return [UIImage imageWithData:target];
}

#pragma mark - image -> nsdata
+(NSData*)imageToNSData:(UIImage*)target{
    return UIImagePNGRepresentation(target);
}

@end
