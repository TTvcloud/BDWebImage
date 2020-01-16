#
# Be sure to run `pod lib lint BDWebImage.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'BDWebImageToB'
  s.version          = '1.0.0'
  s.summary          = 'ByteDance base web image loading and managing library.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keeIp it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = 'ByteDance base web image loading and managing library.'

  s.homepage         = 'http://toutiao.com'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'chenyi' => 'chenyi.0@bytedance.com' }
  s.source           = { :git => 'git@github.com:TTvcloud/BDWebImage.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'
  s.source_files = 'BDWebImage/*.h'
  s.vendored_library = 'BDWebImage/*.a'
  s.frameworks = 'Foundation','UIKit', 'Accelerate', 'ImageIO'
  s.libraries = 'iconv'
  s.public_header_files = 'BDWebImage/*.h'
  s.dependency 'YYCache', '>= 1.0.4'
  s.dependency 'ByteInsights', '>= 0.0.3'
  s.dependency 'libwebp','1.0.3'

end
