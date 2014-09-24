/*
 * Engine.h
 *
 * Copyright (c) 2014, Alessandro Pezzato
 */

#ifndef threescanner_ENGINE_H_
#define threescanner_ENGINE_H_

#include "../prerequisites.h"
#include "PointCloud.h"

#include <opencv2/core/core.hpp>
#include <string>
#include <memory>

namespace threescanner {

class Engine {
public:
	static EnginePtr create(const std::string& type, const Config& cfg);
	static EnginePtr create(const Config& cfg);
	void run();
	virtual ~Engine();
	virtual void startScan() = 0;
	virtual void setParameter(const std::string& key, const std::string& value) = 0;
	virtual void setImage(const std::string& id, const cv::Mat& image) = 0;
	PointCloud::ConstPtr getCloud() const;
	void setInput(ImageInputPtr input);
protected:
	Engine(const Config&);
	ImageInputPtr input_;
	PointCloud::Ptr cloud_;
};

} /* namespace threescanner */

#endif /* threescanner_ENGINE_H_ */
