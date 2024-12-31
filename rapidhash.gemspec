require 'fileutils'

Gem::Specification.new do |s|
  s.name        = 'rapidhash'
  s.version     = '0.0.1'
  s.licenses    = ['MIT']
  s.summary     = "FFI wrapper for the rapidhash hash function"
  s.description = "This gem wraps rapidhash (https://github.com/Nicoshev/rapidhash/tree/master), the successor to wyhash and the fastest hash function passing all tests in SMHasher3."
  s.authors     = ['Praneeth Sadda']
  s.email       = 'psadda@gmail.com'
  s.files       = %w(rapidhash.gemspec) + Dir.glob("{lib,spec,ext}/**/*")
  s.extensions  = ['ext/rapidhash/extconf.rb']
  s.required_ruby_version = '>= 3.0.0'
  s.add_development_dependency 'rake'
  s.metadata    = { 'source_code_uri' => 'https://github.com/psadda/rapidhash-ruby' }
end
