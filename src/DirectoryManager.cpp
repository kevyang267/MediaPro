
#include "DirectoryManager.h"

#include <fstream>
#include <string>

#include <iostream> // TODO: remove


#include <QMediaMetaData>
#include <QMediaPlayer>

namespace MediaPro {

DirectoryManager::DirectoryManager(std::filesystem::path path) {
  libraryPath = path;

  if (std::filesystem::exists(path.append("MediaPro.json"))) {
    std::ifstream file(path);
    json tmp = json::parse(file);
    file.close();

    libraryJson = std::make_shared<json>(tmp);
  } else {
    libraryJson = std::make_shared<json>(R"({
      "tags": {},
      "domainRules": {},
      "orderRules": {},
      "songs": {}
    })"_json);
  }

  for (const std::filesystem::directory_entry& entry : std::filesystem::recursive_directory_iterator(libraryPath)) {
    if (!entry.is_directory()) {
      if (entry.path().extension() == ".mp3") { // TODO(douell8): replace with set of valid file extensions.
        bool getAttributes = false;

        if(libraryJson->at("songs").contains(entry.path())) {
          // TODO(douell8): check last modify date.
        } else {
          libraryJson->at("songs")[entry.path()] = json::object();
          libraryJson->at("songs")[entry.path()]["tags"] = json::array();
          getAttributes = true;
        }

        if (getAttributes) {
          auto player = new QMediaPlayer;

          player->setSource(QUrl::fromLocalFile(entry.path().c_str()));
          const auto metaData = player->metaData();
          
          // std::cout << player->metaData().value(metaData.Title).toString().toStdString() << std::endl;
          std::cout << metaData.isEmpty() << std::endl;
          std::cout << metaData.value(metaData.MediaType).toString().toStdString() << std::endl;

          libraryJson->at("songs")[entry.path()]["title"] = metaData.stringValue(metaData.Title).toStdString();
          // libraryJson->at("songs")[entry.path()]["artists"] = std::string(metaData.stringValue(metaData.Author));
          libraryJson->at("songs")[entry.path()]["album"] = metaData.stringValue(metaData.AlbumTitle).toStdString();
          libraryJson->at("songs")[entry.path()]["length"] = metaData.value(metaData.Duration).toInt();
          // libraryJson->at("songs")[entry.path()]["date"] = std::string(metaData.stringValue(metaData.Date));

          delete player;
        }
      }
    }
  }
}

DirectoryManager::~DirectoryManager() {
  std::ofstream outFile(libraryPath.append("MediaPro.json"));
  outFile << libraryJson->dump(4);
  outFile.close();
}

std::shared_ptr<json> DirectoryManager::getLibrary() {
  return libraryJson;
}

std::filesystem::path DirectoryManager::getPath() {
  return libraryPath;
}

}