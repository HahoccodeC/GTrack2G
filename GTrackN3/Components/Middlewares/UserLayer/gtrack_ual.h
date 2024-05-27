#ifndef __UAL_GTRACK_H
#define __UAL_GTRACK_H

#include "mc60/mc60_pal.h"    // Include the MC60 PAL header
#include "timer/timer_hcl.h"  // Include the HCL Timer header
#include "display/display_pal.h"  // Include the Display PAL header
#include "gtrack_nal.h"  // Include the GTrack NAL header

typedef enum {
    GEOTRACK_DEACTIVATE = 0,
    GEOTRACK_ACTIVATE
} feature_geotrack_state;

/**
 * @brief Initialize the UAL_GTRACK module.
 */
void UAL_GTRACK_Init();

/**
 * @brief Enable the GeoTrack feature.
 */
void UAL_GTRACK_GeoTrack_Enable();

/**
 * @brief Activate the GeoTrack feature with the specified state.
 * 
 * @param state The state to activate the GeoTrack feature.
 */
void UAL_GTRACK_GeoTrack_Activate(feature_geotrack_state state);

/**
 * @brief Get the measurements of the GeoTrack feature.
 */
void UAL_GTRACK_GeoTrack_GetMetric();

#endif