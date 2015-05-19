// Copyright 2015 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef COMPONENTS_LISTENER_H_
#define COMPONENTS_LISTENER_H_

#include "components_generated.h"
#include "entity/entity_manager.h"
#include "entity/component.h"
#include "pindrop/pindrop.h"

namespace fpl {
namespace fpl_project {

// Data for scene object components.
struct AudioListenerData {
  pindrop::Listener listener;
};

class AudioListenerComponent : public entity::Component<AudioListenerData> {
 public:
  void Initialize(pindrop::AudioEngine* audio_engine);

  virtual void InitEntity(entity::EntityRef& entity);
  virtual void AddFromRawData(entity::EntityRef& parent, const void* raw_data);
  virtual void CleanupEntity(entity::EntityRef& entity);
  virtual void UpdateAllEntities(entity::WorldTime delta_time);

 private:
  pindrop::AudioEngine* audio_engine_;
};

}  // fpl_project
}  // fpl

FPL_ENTITY_REGISTER_COMPONENT(fpl::fpl_project::AudioListenerComponent,
                              fpl::fpl_project::AudioListenerData,
                              ComponentDataUnion_ListenerDef)

#endif  // COMPONENTS_LISTENER_H_

