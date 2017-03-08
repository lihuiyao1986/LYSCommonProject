//
//  NSString+MD5.h
//  Encryption
//
//  Created by llyouss on 16/10/16.
//  Copyright © 2016年 llyouss. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>
@interface NSString (MD5)
//md5加密
- (NSString *)md5Encrypt;
//sha－1 加密
- (NSString *)sha1Encrypt;
@end
