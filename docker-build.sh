#!/bin/bash
set -e

# Check if a project name was provided
if [ -z "$1" ]; then
  echo "Usage: $0 <project_name>"
  echo "Example: $0 process_monitor"
  exit 1
fi

PROJECT_NAME=$1

# Check if the project directory exists
if [ ! -d "$PROJECT_NAME" ]; then
  echo "Error: Project directory '$PROJECT_NAME' not found"
  exit 1
fi

# Clean up any existing build artifacts
echo "Cleaning up existing build artifacts..."
rm -rf "$PROJECT_NAME/build"

# Create build directory
echo "Creating build directory..."
mkdir -p "$PROJECT_NAME/build"

# Run docker commands
echo "Building $PROJECT_NAME in Docker container..."
docker-compose exec -T dev bash -c "cd /workspace/$PROJECT_NAME && mkdir -p build && cd build && cmake .. && make"

echo "Build complete. To run the program:"
echo "docker-compose exec dev bash -c \"cd /workspace/$PROJECT_NAME/build && ./monitor\""
