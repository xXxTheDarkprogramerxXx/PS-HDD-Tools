#ifndef CELL_FORMAT_HPP
#define CELL_FORMAT_HPP

#include <vector>
#include <stdint.h>

#include "disk_format.hpp"
#include "partition/ps3.h"

#include <io/data/data_provider.hpp>

namespace formats {

/**
 * @brief Detects and loads the PS3 disk format.
 */
class CellDiskFormat : public IDiskFormat
{
public:
  CellDiskFormat() {}
  
  bool match(disk::Disk* disk, disk::DiskConfig* config) override;
  void build(disk::Disk* disk, disk::DiskConfig* config) override;

private:
  /**
   * @brief Generate crypto keys from an eid root key.
   * 
   * @param eidRootKey 
   */
  void generateKeys(std::vector<char>& eidRootKey);

  std::vector<char> ataKeys;
  std::vector<char> encDecKeys;
  const uint32_t kSectorSize = 0x200;
  enum class Ps3Type {UNK,PHAT,SLIM/*,ARC*/} type = Ps3Type::UNK;
};

} /* namespace formats */

#endif /* CELL_FORMAT_HPP */
