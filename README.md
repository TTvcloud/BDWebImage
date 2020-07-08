# BDWebImage

## Demo演示

1. `git clone git@github.com:TTvcloud/BDWebImage.git`
2. `cd BDWebImage/Eample`
3. `pod install`
4. `open BDWebImage.xcworkspace`

## 使用文档
https://www.byteoc.com/docs/508/19946/
注册登陆成功后可查看，有疑问请联系客服

## BDWebImage 接入

```rub
pod 'BDWebImageToB',:git => 'https://github.com/TTvcloud/BDWebImage.git', :tag => '1.1.2', :subspecs => [
      'Core',
      'SDInterface'
  ]
```

或者

```ruby
source 'git@github.com:bytedance/cocoapods_sdk_source_repo.git'

pod 'BDWebImageToB', '1.1.2',:subspecs => [
      'Core',
      'SDInterface'
  ]
```

```
pod install --repo-update
```


## 要求

特别说明，只支持Xcode 10以上打包开发，Xcode 10以下，请单独联系开发提供SDK包

* iOS 8.0+
* Xcode 10
