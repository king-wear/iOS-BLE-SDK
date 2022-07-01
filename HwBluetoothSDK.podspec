Pod::Spec.new do |spec|

  spec.name         = "HwBluetoothSDK"
  spec.version      = "3.2.7"
  spec.summary      = "iOS Bluetooth SDK"

  spec.description  = <<-DESC
    iOS Bluetooth SDK
                   DESC

  spec.homepage     = "https://github.com/king-wear/iOS-BLE-SDK"
  spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }

  spec.author             = { "sujiang" => "sujiang@huawo-wear.com" }

  spec.source       = { :git => "https://github.com/king-wear/iOS-BLE-SDK.git", :tag => "#{spec.version}" }

  # spec.framework  = "HwBluetoothSDK"
  spec.frameworks = "UIKit", "Foundation"

  # spec.library   = "iconv"
  # spec.libraries = "iconv", "xml2"

  spec.requires_arc = true

  # spec.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # spec.dependency "JSONKit", "~> 1.4"
end
