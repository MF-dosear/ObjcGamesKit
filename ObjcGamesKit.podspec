Pod::Spec.new do |s|
  s.name             = 'ObjcGamesKit'
  s.version          = '1.0.0'
  s.summary          = 'OC 游戏SDK'

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/MF-dosear/ObjcGamesKit'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Paul' => 'dosear@qq.com' }
  s.source           = { :git => 'https://github.com/MF-dosear/ObjcGamesKit.git', :tag => s.version.to_s }
  
  s.ios.deployment_target = '12.0'

  s.requires_arc = true
  
  valid_archs = ['arm64',]

  s.pod_target_xcconfig = {
    'VALID_ARCHS[sdk=iphonesimulator*]' => ''
  }

  s.vendored_frameworks = ['ObjcGamesKit/Frameworks/**/*.framework']

end
