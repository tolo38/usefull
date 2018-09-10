

#OPENCV


cv::Mat
---

std::cout << mat;                                       display content
mat(cv::Rect(x,y,width,height))                         submatrix
mat({x,x+width},{y,y+height});                          CAUTION : w,h start to 1
cv::Mat(3,4,CV_64F,vec.data()).copyTo(_proj_top);       from STL to matrix
if (mat->isContinuous()) {                              from matrix to STL
        list->assign((vec3d_t*)mat->datastart, (vec3d_t*)mat->dataend);
} else {
        list->reserve(mat->rows);
        for (int i = 0; i < mat->rows; ++i) {
                list->insert(list->end(), mat->ptr<vec3d_t>(i), mat->ptr<vec3d_t>(i)+mat->cols);
        }
}
cv::Mat diff;                                           check matrix content
cv::compare(mat1, mat2, diff, cv::CMP_NE);
int nz = cv::countNonZero(diff);

calibration Camera
---