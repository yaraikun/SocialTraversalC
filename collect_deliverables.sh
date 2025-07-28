#!/bin/bash

# =============================================================================
# collect_deliverables.sh
#
# This script gathers all necessary project files and artifacts and places
# them directly into a 'deliverables' folder with a flat structure. It
# specifically excludes the 'logs' directory from the collection.
#
# Usage:
#   ./collect_deliverables.sh
# =============================================================================

# --- Configuration ---
# Source Directories
INCLUDE_DIR="include"
SRC_DIR="src"
DATA_DIR="data"
OUT_DIR="out"
SPECS_DIR="specs"

# Source Files
DOC_PDF="${SPECS_DIR}/66.pdf"

# Destination Directory
DELIVERABLES_DIR="deliverables"

# --- Main Script ---
echo "========================================"
echo "    Collecting Project Deliverables"
echo "========================================"
echo

# Flag to track if any warnings occurred
warnings_found=0

# 1. Setup the deliverables directory
echo "--- Preparing destination directory..."
rm -rf "$DELIVERABLES_DIR"
mkdir -p "$DELIVERABLES_DIR"
echo "    - Clean directory created at: $DELIVERABLES_DIR/"
echo

# 2. Collect files
echo "--- Copying project files into '$DELIVERABLES_DIR/'..."

# --- Collect .h files ---
echo "    -> Searching for header files in '${INCLUDE_DIR}/'..."
if [ -d "$INCLUDE_DIR" ] && [ "$(ls -A ${INCLUDE_DIR}/*.h 2>/dev/null)" ]; then
    cp -v "${INCLUDE_DIR}"/*.h "${DELIVERABLES_DIR}/"
else
    echo "       WARNING: No .h files found. Skipping."
    warnings_found=1
fi

# --- Collect .c files ---
echo "    -> Searching for source files in '${SRC_DIR}/'..."
if [ -d "$SRC_DIR" ] && [ "$(ls -A ${SRC_DIR}/*.c 2>/dev/null)" ]; then
    cp -v "${SRC_DIR}"/*.c "${DELIVERABLES_DIR}/"
else
    echo "       WARNING: No .c files found. Skipping."
    warnings_found=1
fi

# --- Collect data files ---
echo "    -> Searching for data files in '${DATA_DIR}/'..."
if [ -d "$DATA_DIR" ] && [ "$(ls -A ${DATA_DIR}/*.TXT 2>/dev/null)" ]; then
    cp -v "${DATA_DIR}"/*.TXT "${DELIVERABLES_DIR}/"
else
    echo "       WARNING: Data directory is empty or does not exist. Skipping."
    warnings_found=1
fi

# --- Collect output files (excluding logs) ---
echo "    -> Searching for output files in '${OUT_DIR}/'..."
if [ -d "$OUT_DIR" ] && [ "$(ls -A ${OUT_DIR} 2>/dev/null)" ]; then
    # Loop through each item in the output directory
    for subdir in "${OUT_DIR}"/*; do
        # Process only if it's a directory AND its name is not 'logs'
        if [ -d "$subdir" ] && [ "$(basename "$subdir")" != "logs" ]; then
            echo "       Copying contents of '$subdir/'..."
            # Copy contents of the valid subdirectory into the flat deliverables dir
            # The '2>/dev/null' suppresses errors if a subdir is empty
            cp -v "${subdir}"/* "${DELIVERABLES_DIR}/" 2>/dev/null
        fi
    done
else
    echo "       WARNING: Output directory '${OUT_DIR}/' is empty or does not exist. Skipping."
    warnings_found=1
fi

# --- Collect documentation PDF ---
echo "    -> Searching for documentation PDF..."
if [ -f "$DOC_PDF" ]; then
    cp -v "$DOC_PDF" "${DELIVERABLES_DIR}/"
else
    echo "       WARNING: Documentation file not found at '${DOC_PDF}'. Skipping."
    warnings_found=1
fi
echo

# 3. Final Summary
echo "========================================"
echo "         Collection Complete"
echo "========================================"
if [ $warnings_found -eq 1 ]; then
    echo "  > PROCESS COMPLETED WITH WARNINGS."
    echo "    Please review the log above to see which files were not found."
else
    echo "  > All found files collected successfully."
fi
echo "  > Check the contents of the '${DELIVERABLES_DIR}/' directory."
echo "========================================"
