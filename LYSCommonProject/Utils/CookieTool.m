//
//  CookieTool.m
//  LYSCommonProject
//
//  Created by jk on 2017/3/8.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import "CookieTool.h"

@implementation CookieTool

#pragma mark - 获取服务端的cookies
+(NSArray<NSHTTPCookie*>*)getServerCookies:(NSHTTPURLResponse*)response url:(NSString*)url{
    //获取cookie
    NSDictionary *headers = [response allHeaderFields];
    NSLog(@"headers:%@",headers);
    NSArray<NSHTTPCookie*> *cookies = [NSHTTPCookie cookiesWithResponseHeaderFields:headers forURL:[NSURL URLWithString:url]];
    return cookies;
}

#pragma mark - 根据cookie名称获取对应的服务端的cookie对象
+(NSHTTPCookie*)getServerCookieByName:(NSString*)cookieName response:(NSHTTPURLResponse*)response url:(NSString*)url{
    NSArray<NSHTTPCookie*> *cookies = [CookieTool getServerCookies:response url:url];
    for (NSHTTPCookie *cookie in cookies) {
        if ([cookie.name isEqualToString:cookieName]) {
            return cookie;
        }
    }
    return nil;
}

#pragma mark - 获取客户端的cookies
+(NSArray<NSHTTPCookie*>*)getClientCookies:(NSString*)url{
    //获取本地cookie
    NSHTTPCookieStorage *httpCookiesStorage =  [NSHTTPCookieStorage sharedHTTPCookieStorage];
    NSArray<NSHTTPCookie*> *cookies = [httpCookiesStorage cookiesForURL:[NSURL URLWithString:url]];
    return cookies;
}

#pragma mark - 根据cookie名称获取对应的客户端的cookie对象
+(NSHTTPCookie*)getClientCookieByName:(NSString*)cookieName url:(NSString*)url{
    NSArray<NSHTTPCookie*> *cookies = [CookieTool getClientCookies:url];
    for (NSHTTPCookie *cookie in cookies) {
        if ([cookie.name isEqualToString:cookieName]) {
            return cookie;
        }
    }
    return nil;
}

#pragma mark - 设置客户端的cookies
+(void)setClientCookies:(NSArray<NSDictionary*>*)cookies cookiePolicy:(NSHTTPCookieAcceptPolicy)cookiePolicy{
    
    for (NSDictionary* item in cookies) {
        NSHTTPCookie * cookie = [NSHTTPCookie cookieWithProperties:item];
        [[NSHTTPCookieStorage sharedHTTPCookieStorage] setCookie:cookie];
    }
    
    //批量设置
    //   NSArray *cookies = @[cookie1,cookie2,cookie3];
    //   [[NSHTTPCookieStorage sharedHTTPCookieStorage]setCookies:cookies forURL:[NSURL URLWithString:@"http://localhost/"] mainDocumentURL:nil];
    
    //设置cookie本地缓存策略
    //NSHTTPCookieAcceptPolicyAlways:保存所有cookie，这个是默认值
    //NSHTTPCookieAcceptPolicyNever:不保存任何响应头中的cookie
    //NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain:只保存域请求匹配的cookie
    
    [[NSHTTPCookieStorage sharedHTTPCookieStorage]setCookieAcceptPolicy:cookiePolicy];
}

#pragma mark - 删除cookie
+(void)deleteCookie:(NSString *)cookieName url:(NSURL *)url{
    //根据url找到所属的cookie集合
    NSArray *cookies = [[NSHTTPCookieStorage sharedHTTPCookieStorage]cookiesForURL:url];
    for (NSHTTPCookie *cookie in cookies) {
        if([cookie.name isEqualToString:cookieName]){
            [[NSHTTPCookieStorage sharedHTTPCookieStorage] deleteCookie:cookie];
            break;
        }
    }
}

#pragma mark - 删除全部cookies
+(void)deleteAllCookies{
    for (NSHTTPCookie *cookie in [[NSHTTPCookieStorage sharedHTTPCookieStorage]cookies]) {
        [[NSHTTPCookieStorage sharedHTTPCookieStorage] deleteCookie:cookie];
    }
}

@end
