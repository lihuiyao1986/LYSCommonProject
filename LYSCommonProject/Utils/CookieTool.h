//
//  CookieTool.h
//  LYSCommonProject
//
//  Created by jk on 2017/3/8.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CookieTool : NSObject


#pragma mark - 获取服务端的cookies
+(NSArray<NSHTTPCookie*>*)getServerCookies:(NSHTTPURLResponse*)response url:(NSString*)url;

#pragma mark - 根据cookie名称获取对应的服务端的cookie对象
+(NSHTTPCookie*)getServerCookieByName:(NSString*)cookieName response:(NSHTTPURLResponse*)response url:(NSString*)url;

#pragma mark - 获取客户端的cookies
+(NSArray<NSHTTPCookie*>*)getClientCookies:(NSString*)url;

#pragma mark - 根据cookie名称获取对应的客户端的cookie对象
+(NSHTTPCookie*)getClientCookieByName:(NSString*)cookieName url:(NSString*)url;

#pragma mark - 设置客户端的cookies
+(void)setClientCookies:(NSArray<NSDictionary*>*)cookies;

#pragma mark -客户端删除cookie
+(void)deleteCookie:(NSString *)cookieName url:(NSURL *)url;

#pragma mark - 删除全部cookies
+(void)deleteAllCookies;

@end
