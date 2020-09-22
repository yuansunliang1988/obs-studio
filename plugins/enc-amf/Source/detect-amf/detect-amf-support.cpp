/*
 * Piped program that detects AMF support to prevent startup crashes
 * Copyright (C) 2018 Hugh Bailey
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "plugin.h"
#include "api-base.h"
#include "amf.h"
#include "amf-capabilities.h"
#include <sstream>

int main(void) {
	SetErrorMode(SEM_NOGPFAULTERRORBOX | SEM_FAILCRITICALERRORS);

	try {
		// AMF
		Plugin::AMD::AMF::Initialize();

		// Initialize Graphics APIs
		Plugin::API::InitializeAPIs();

		Plugin::AMD::CapabilityManager::Initialize();
	} catch (...) {
		return 2;
	}

	Plugin::AMD::CapabilityManager::Finalize();
	Plugin::API::FinalizeAPIs();
	Plugin::AMD::AMF::Finalize();
	return 3;
}
