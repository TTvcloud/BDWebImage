#
# Be sure to run `pod lib lint BDWebImage.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'BDWebImageToB'
  s.version          = '1.1.2'
  s.summary          = 'iOS base web image loading and managing library.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = 'iOS base web image loading and managing library.'

  s.homepage         = 'http://toutiao.com'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'chenyi' => 'chenyi.0@bytedance.com' }
  s.source           = { :git => 'https://github.com/TTvcloud/BDWebImage.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'
  
  s.default_subspecs = 'Core'

  s.subspec 'Core' do |core|
    core.requires_arc =  true
    core.source_files = 'BDWebImage/*.h'
    core.vendored_library = 'BDWebImage/*.a'
    core.public_header_files = 'BDWebImage/*.h'
    core.frameworks = 'Foundation','UIKit', 'Accelerate', 'ImageIO', 'CoreServices','CoreGraphics'
    core.libraries = 'iconv'
    core.dependency 'ByteInsights', '>= 0.0.3'
    core.dependency 'libwebp','>= 1.0.0'
  end
  
  s.subspec 'SDInterface' do |sdi|
    sdi.source_files = 'BDWebImage/SDInterface/*.h'
    sdi.vendored_library = 'BDWebImage/SDInterface/*.a'
    sdi.public_header_files = 'BDWebImage/SDInterface/*.h'
    sdi.dependency 'BDWebImageToB/Core'
  end
   
end
