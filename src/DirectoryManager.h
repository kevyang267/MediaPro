
#include <filesystem>
#include <memory>

#include <nlohmann/json.hpp>


using nlohmann::json;

namespace MediaPro {

class DirectoryManager {

private:
  std::filesystem::path libraryPath;
  std::shared_ptr<json> libraryJson;

public:
  DirectoryManager(std::filesystem::path path);
  ~DirectoryManager();

  std::shared_ptr<json> getLibrary();
  std::filesystem::path getPath();
};
}