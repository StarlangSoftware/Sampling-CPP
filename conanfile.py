from conans import ConanFile, CMake, tools


class SamplingConan(ConanFile):
    name = "Sampling"
    version = "1.0.0"
    license = "GPL License"
    author = "Olcay Taner Yildiz olcay.yildiz@ozyegin.edu.tr"
    url = "https://github.com/StarlangSoftware/Sampling-CPP"
    description = "Simple Sampling Library"
    topics = ("")
    exports_sources = "src/*"
    no_copy_source = True

    def package(self):
        self.copy("*.h", dst="include", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["Sampling"]
