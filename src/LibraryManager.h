
#include <map>
#include <memory>
#include <string>

#include <nlohmann/json.hpp>

#include "DirectoryManager.h"
#include "Tag.h"
#include "Song.h"
#include "DomainRule.h"
#include "OrderRule.h"
#include "Queue.h"


using nlohmann::json;

namespace MediaPro {

class LibraryManager {

private:
  DirectoryManager dirManager;
  std::shared_ptr<Queue> queue;

  std::map<std::string, std::shared_ptr<MediaPro::Tag>> tags;
  std::map<std::string, std::shared_ptr<Song>> songs;
  std::map<std::string, std::shared_ptr<DomainRule>> domainRules;
  std::map<std::string, std::shared_ptr<OrderRule>> orderRules;

  void update();

public:
  LibraryManager(std::string path);
  ~LibraryManager();

  std::vector<std::shared_ptr<Song>> search(std::string key, int category = 0);

  std::shared_ptr<Queue> getQueue();

  std::shared_ptr<Tag> getTag(std::string key);
  std::shared_ptr<Song> getSong(std::string key);
  std::shared_ptr<DomainRule> getDomainRule(std::string key);
  std::shared_ptr<OrderRule> getOrderRule(std::string key);

  bool addTag(std::shared_ptr<Tag> tag);
  bool addDomainRule(std::shared_ptr<DomainRule> rule);
  bool addOrderRule(std::shared_ptr<OrderRule> rule);

  bool editTag(std::string key, std::shared_ptr<Tag> tag);
  bool editDomainRule(std::string key, std::shared_ptr<DomainRule> rule);
  bool editOrderRule(std::string key, std::shared_ptr<OrderRule> rule);

  bool removeTag(std::string key);
  bool removeDomainRule(std::string key);
  bool removeOrderRule(std::string key);
};

}
