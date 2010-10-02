// Konstruktor - An interactive LDraw modeler for KDE
// Copyright (c)2006 Park "segfault" J. K. <mastermind@planetmono.org>

#include "povrayrenderparameters.h"

// TODO copy all props

KonstruktorPOVRayRenderParameters::KonstruktorPOVRayRenderParameters()
{
	width_ = 512;
	height_ = 384;
	antialiasing_ = true;

	seamWidth_ = 0.8f;
	
	backgroundColor_ = QColor(64, 64, 64);
	
	drawPlane_ = true;
	planePositionAuto_ = true;
	planePosition_ = 0.0f;
	planeColor_ = QColor(165, 165, 165);
	
	latitude_ = 135.0f;
	longitude_ = 30.0f;
	radius_ = 1.0f;
	fov_ = 60.0f;
	orthographic_ = false;
	
	lights_ = 2;
	lightsLongitude_ = 60.0f;
	lightsLatitudeOffset_ = 180.0f - 22.5f;
	lightsRadius_ = 2.0f;
	lightsIntensity_ = 1.5f;
	lightsColor_ = QColor(255, 255, 255);
}

KonstruktorPOVRayRenderParameters::KonstruktorPOVRayRenderParameters(const KonstruktorPOVRayRenderParameters &p)
{
	width_ = p.width();
	height_ = p.height();
	antialiasing_ = p.antialiasing();
}

KonstruktorPOVRayRenderParameters KonstruktorPOVRayRenderParameters::operator= (const KonstruktorPOVRayRenderParameters &p) const
{
	KonstruktorPOVRayRenderParameters n;
	
	n.setWidth(p.width());
	n.setHeight(p.height());
	n.setAntialiasing(p.antialiasing());
	
	return n;
}