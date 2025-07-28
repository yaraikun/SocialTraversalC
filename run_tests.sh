#!/bin/bash

# =============================================================================
# test_runner.sh
#
# A simple and clean test script for the SocialNetwork project.
#
# Usage:
#   ./test_runner.sh        - Runs the full test suite.
#   ./test_runner.sh clean  - Removes the output directory.
# =============================================================================

# --- Configuration ---
EXECUTABLE="./bin/SocialNetwork"
DATA_DIR="./data"
OUT_DIR="./out"
LOG_DIR="${OUT_DIR}/logs" # A single, central directory for all logs

# --- Test Cases ---
INPUT_FILES=(
    "GRAPH5.TXT"
    "GRAPH10.TXT"
    "GRAPH20.TXT"
)
START_VERTICES=(
    "A" # Example start vertex for GRAPH5.TXT
    "A" # Example start vertex for GRAPH10.TXT
    "A" # Example start vertex for GRAPH20.TXT
)

# --- Argument Handling ---
# Check for the "clean" command
if [ "$1" = "clean" ]; then
    echo "--- Cleaning up output directory ---"
    if [ -d "$OUT_DIR" ]; then
        rm -rf "$OUT_DIR"
        echo "Directory '$OUT_DIR' has been removed."
    else
        echo "Directory '$OUT_DIR' does not exist. Nothing to clean."
    fi
    exit 0
fi

# =============================================================================
# --- Main Script Execution (if not cleaning) ---
# =============================================================================

echo "========================================"
echo "      SocialNetwork Test Runner"
echo "========================================"
echo

# 1. Pre-flight Checks
echo "--- [1] Checking prerequisites..."
if [ ! -f "$EXECUTABLE" ]; then
    echo "    ERROR: Executable not found at '$EXECUTABLE'. Please compile first."
    exit 1
fi
echo "    - Executable found."

if [ ! -d "$DATA_DIR" ]; then
    echo "    - ERROR: Data directory not found at '$DATA_DIR'."
    exit 1
fi
echo "    - Data directory found."
echo

# 2. Setup Test Environment
echo "--- [2] Preparing test environment..."
# Ensure a clean slate by removing and recreating the main directories.
rm -rf "$OUT_DIR"
mkdir -p "$OUT_DIR"
mkdir -p "$LOG_DIR" # Create the central log directory
echo "    - Clean output directories created."
echo

# 3. Run Test Suite
echo "--- [3] Executing test cases..."
for i in "${!INPUT_FILES[@]}"; do
    input_file_path="${DATA_DIR}/${INPUT_FILES[$i]}"
    start_vertex="${START_VERTICES[$i]}"

    # Define names and paths for this specific test case
    base_name=$(basename "$input_file_path" .TXT)
    case_output_dir="${OUT_DIR}/${base_name}"
    log_file_path="${LOG_DIR}/${base_name}_run.log" # Log goes to the central dir

    echo "    -> Running test for: ${base_name}"

    # Create the dedicated directory for this test case's output files
    mkdir -p "$case_output_dir"

    # Check for input file before running
    if [ ! -f "$input_file_path" ]; then
        echo "       STATUS: FAILED (Input file not found)"
        continue
    fi

    # Run the program and redirect its console output to the central log file
    printf "%s\n%s\n" "$input_file_path" "$start_vertex" | $EXECUTABLE > "$log_file_path"

    # Move generated *.TXT files into the case-specific output directory
    mv ./${base_name}-*.TXT "$case_output_dir/" 2>/dev/null

    if [ $? -eq 0 ]; then
        echo "       STATUS: SUCCESS (Output in: ${case_output_dir}/)"
    else
        echo "       STATUS: WARNING (No output files were generated)"
        echo "       (Check log: ${log_file_path})"
    fi
done
echo

# 4. Final Summary
echo "========================================"
echo "            Tests Complete"
echo "========================================"
echo "  > Output files are in subdirectories inside: $OUT_DIR"
echo "  > All console run logs are in:              $LOG_DIR"
echo "  > To remove all output, run: ./test_runner.sh clean"
echo "========================================"
