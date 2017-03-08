//
//  EncryptTool.h
//  LYSCommonProject
//
//  Created by jk on 2017/3/8.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>

@interface EncryptTool : NSObject

#pragma mark-  md5加密
+(NSString *)getMD5:(NSString *)input;

#pragma mark- 接收数据时,NSData－>Byte数组->16进制数
+(NSString *)nsdataToByteToHex:(NSData *)data;

#pragma mark-  普通字符串转换为十六进制的字符串
+ (NSString *)hexStringFromString:(NSString *)string;

#pragma mark-  nsdata转换成十六进制的字符串
+ (NSString *)hexStringFromNSData:(NSData *)data;

#pragma mark-  十六进制字符串转换成nsdata
+ (NSData *)convertHexStrToData:(NSString *)str;

@end
