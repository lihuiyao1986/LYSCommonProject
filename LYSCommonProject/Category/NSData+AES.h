//
//  NSData+AES.h
//  Encryption
//
//  Created by llyouss on 16/10/16.
//  Copyright © 2016年 llyouss. All rights reserved.
//

#import <Foundation/Foundation.h>
@class NSString;
@interface NSData (AES)
- (NSData *)AES256EncryptWithKey:(NSString *)key;   //加密
- (NSData *)AES256DecryptWithKey:(NSString *)key;   //解密
@end
