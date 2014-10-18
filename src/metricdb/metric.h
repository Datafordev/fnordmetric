/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef _FNORDMETRIC_METRICDB_METRIC_H_
#define _FNORDMETRIC_METRICDB_METRIC_H_
#include <fnordmetric/io/filerepository.h>
#include <fnordmetric/metricdb/sample.h>
#include <string>
#include <vector>

using namespace fnord;
namespace fnordmetric {
namespace metricdb {

class Metric {
public:
  Metric(const std::string& key, io::FileRepository* file_repo);

  void addSample(const Sample<double>& sample);

protected:
  struct SSTableRef {
    std::string filename;
    uint64_t first_key;
    uint64_t last_key;
  };

  std::vector<SSTableRef> sstables_;
};

}
}
#endif