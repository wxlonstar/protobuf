// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Author: kenton@google.com (Kenton Varda)
//  Based on original Protocol Buffers design by
//  Sanjay Ghemawat, Jeff Dean, and others.

#ifndef GOOGLE_PROTOBUF_COMPILER_JAVA_PRIMITIVE_FIELD_LITE_H__
#define GOOGLE_PROTOBUF_COMPILER_JAVA_PRIMITIVE_FIELD_LITE_H__

#include <map>
#include <string>
#include <google/protobuf/compiler/java/java_field.h>

namespace unity {
namespace google {
namespace protobuf {
namespace compiler {
namespace java {
class Context;            // context.h
class ClassNameResolver;  // name_resolver.h
}  // namespace java
}  // namespace compiler
}  // namespace protobuf
}  // namespace google
}  // namespace unity

namespace unity {
namespace google {
namespace protobuf {
namespace compiler {
namespace java {

class ImmutablePrimitiveFieldLiteGenerator
    : public ImmutableFieldLiteGenerator {
 public:
  explicit ImmutablePrimitiveFieldLiteGenerator(
      const FieldDescriptor* descriptor, int messageBitIndex, Context* context);
  ~ImmutablePrimitiveFieldLiteGenerator();

  // implements ImmutableFieldLiteGenerator
  // ------------------------------------
  int GetNumBitsForMessage() const;
  void GenerateInterfaceMembers(io::Printer* printer) const;
  void GenerateMembers(io::Printer* printer) const;
  void GenerateBuilderMembers(io::Printer* printer) const;
  void GenerateInitializationCode(io::Printer* printer) const;
  void GenerateFieldInfo(io::Printer* printer,
                         std::vector<uint16>* output) const;

  std::string GetBoxedType() const;

 protected:
  const FieldDescriptor* descriptor_;
  std::map<std::string, std::string> variables_;
  const int messageBitIndex_;
  ClassNameResolver* name_resolver_;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(ImmutablePrimitiveFieldLiteGenerator);
};

class ImmutablePrimitiveOneofFieldLiteGenerator
    : public ImmutablePrimitiveFieldLiteGenerator {
 public:
  ImmutablePrimitiveOneofFieldLiteGenerator(const FieldDescriptor* descriptor,
                                            int messageBitIndex,
                                            Context* context);
  ~ImmutablePrimitiveOneofFieldLiteGenerator();

  void GenerateMembers(io::Printer* printer) const;
  void GenerateBuilderMembers(io::Printer* printer) const;

  void GenerateFieldInfo(io::Printer* printer,
                         std::vector<uint16>* output) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(ImmutablePrimitiveOneofFieldLiteGenerator);
};

class RepeatedImmutablePrimitiveFieldLiteGenerator
    : public ImmutableFieldLiteGenerator {
 public:
  explicit RepeatedImmutablePrimitiveFieldLiteGenerator(
      const FieldDescriptor* descriptor, int messageBitIndex, Context* context);
  virtual ~RepeatedImmutablePrimitiveFieldLiteGenerator();

  // implements ImmutableFieldLiteGenerator ------------------------------------
  int GetNumBitsForMessage() const;
  void GenerateInterfaceMembers(io::Printer* printer) const;
  void GenerateMembers(io::Printer* printer) const;
  void GenerateBuilderMembers(io::Printer* printer) const;
  void GenerateInitializationCode(io::Printer* printer) const;
  void GenerateFieldInfo(io::Printer* printer,
                         std::vector<uint16>* output) const;

  std::string GetBoxedType() const;

 private:
  const FieldDescriptor* descriptor_;
  std::map<std::string, std::string> variables_;
  Context* context_;
  ClassNameResolver* name_resolver_;

  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(RepeatedImmutablePrimitiveFieldLiteGenerator);
};

}  // namespace java
}  // namespace compiler
}  // namespace protobuf
}  // namespace google
}  // namespace unity

#endif  // GOOGLE_PROTOBUF_COMPILER_JAVA_PRIMITIVE_FIELD_LITE_H__
