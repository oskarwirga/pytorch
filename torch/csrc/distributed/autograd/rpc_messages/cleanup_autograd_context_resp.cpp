#include <torch/csrc/distributed/autograd/rpc_messages/cleanup_autograd_context_resp.h>

namespace torch {
namespace distributed {
namespace autograd {

c10::intrusive_ptr<rpc::OutgoingMessage> CleanupAutogradContextResp::toMessageImpl(const std::string& meta) && {
  std::vector<torch::Tensor> tensors;
  std::vector<char> payload;
  return c10::make_intrusive<rpc::OutgoingMessage>(
      std::move(payload),
      std::move(tensors),
      rpc::MessageType::CLEANUP_AUTOGRAD_CONTEXT_RESP,
      meta);
}

std::unique_ptr<CleanupAutogradContextResp> CleanupAutogradContextResp::
    fromMessage(const rpc::Message& message /* unused */) {
  return std::unique_ptr<CleanupAutogradContextResp>();
}

} // namespace autograd
} // namespace distributed
} // namespace torch
