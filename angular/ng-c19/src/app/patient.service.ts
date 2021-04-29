import { Injectable } from '@angular/core';
import { HttpClient, HttpErrorResponse } from '@angular/common/http';
import { IPatient } from './IPatient';
import { Observable } from 'rxjs/internal/Observable';

import { catchError} from 'rxjs/operators';


@Injectable({
  providedIn: 'root'
})
export class PatientService {

  private _url: string = "http://localhost:8081/graph";

  constructor(private http:HttpClient) { }

  getPatients(): Observable<IPatient[]>{
    return this.http.get<IPatient[]>(this._url)
      .pipe(
        catchError(this.handleError)
      );
  }

  handleError(handleError: any): import("rxjs").OperatorFunction<IPatient[], any>{
    throw new Error(handleError.message || "Server error");
  };

}


